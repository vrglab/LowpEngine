#include "pch.h"
#include "Directx12Framework.h"
#include <SDL2/SDL_syswm.h>
#include <SceneEngine/SceneManager.h>

#ifdef EDITOR
#include <ImGui/imgui.h>
#include <ImGui/misc/cpp/imgui_stdlib.h>
#include <ImGui/backends/imgui_impl_sdl2.h>
#ifdef _WIN32
#include <ImGui/backends/imgui_impl_dx12.h>
#endif
#endif

void Directx12Framework::Init(Ref<ApplicationInfo> init_info, SDL_Window* window)
{
#ifdef _WIN32
    LP_CORE_INFO("Starting DirectX12");
    this->window_access = window;
	SDL_SetHint(SDL_HINT_RENDER_DRIVER, "direct3d12");
    if (D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device)) < 0) {
        LP_CORE_ERROR("DirectX12 device creation failed");
    }

    D3D12_COMMAND_QUEUE_DESC cqDesc = {};
    cqDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
    cqDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

    if (device->CreateCommandQueue(&cqDesc, IID_PPV_ARGS(&commandQueue)) < 0) {
        LP_CORE_ERROR("DirectX12 command que creation failed");
    }

    DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
    swapChainDesc.BufferCount = 2; // Double buffering
    swapChainDesc.Width = init_info->resolution->width;
    swapChainDesc.Height = init_info->resolution->height;
    swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    swapChainDesc.SampleDesc.Count = 1;


    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    if (SDL_GetWindowWMInfo(window, &wmInfo) == SDL_FALSE) {
        LP_CORE_ERROR("Failed to retrive window HWND");
    }
    
    IDXGISwapChain1* tempSwapChain;
    CreateDXGIFactory1(IID_PPV_ARGS(&dxgiFactory));
    HRESULT hrresult_swapchain = dxgiFactory->CreateSwapChainForHwnd(
        commandQueue,
        wmInfo.info.win.window,
        &swapChainDesc,
        nullptr,
        nullptr,
        &tempSwapChain
    );

    if (FAILED(hrresult_swapchain)) {
        LP_CORE_ERROR("DirectX12 swapchain creation failed");
    }

    // Query for IDXGISwapChain3 interface from the created IDXGISwapChain1
    HRESULT hr = tempSwapChain->QueryInterface(__uuidof(IDXGISwapChain3), reinterpret_cast<void**>(&swapChain));
    if (FAILED(hr)) {
        LP_CORE_ERROR("DirectX12 swapchain creation failed");
    }


    // Create the Render Target View (RTV) heap
    D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
    rtvHeapDesc.NumDescriptors = 2; // Double buffering
    rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&rtvHeap));

    SIZE_T rtvDescriptorSize = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
    D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle(rtvHeap->GetCPUDescriptorHandleForHeapStart());

    for (UINT n = 0; n < 2; n++) {
        swapChain->GetBuffer(n, IID_PPV_ARGS(&renderTargets[n]));
        device->CreateRenderTargetView(renderTargets[n], nullptr, rtvHandle);

        // Offset the handle for the next descriptor
        rtvHandle.ptr += rtvDescriptorSize;
    }

    // Create a command allocator
    device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&commandAllocator));

    // Create a command list
    device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, commandAllocator, nullptr, IID_PPV_ARGS(&commandList));
#ifdef EDITOR
    ImGui_ImplDX12_Init(device, 3, DXGI_FORMAT_R8G8B8A8_UNORM, rtvHeap, 
        rtvHeap->GetCPUDescriptorHandleForHeapStart(), 
        rtvHeap->GetGPUDescriptorHandleForHeapStart());
#endif
#else
    LP_CORE_ERROR("DirectX12 is not supported on this device");
#endif
}

void Directx12Framework::Tick()
{
#ifdef _WIN32
#ifdef EDITOR
    ImGui_ImplDX12_CreateDeviceObjects();
#endif

#ifdef GAME
    D3D12_CPU_DESCRIPTOR_HANDLE currentRtvHandle(rtvHeap->GetCPUDescriptorHandleForHeapStart());
    SIZE_T rtvDescriptorIncrement = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
    currentRtvHandle.ptr += swapChain->GetCurrentBackBufferIndex() * rtvDescriptorIncrement;
        float* clear_Color = static_cast<float*>(current_scene->configs.GetConfig("bgd_color"));
        float clearColors[] = { clear_Color[0], clear_Color[1], clear_Color[2], clear_Color[3] };
        commandList->ClearRenderTargetView(currentRtvHandle, clearColors, 0, nullptr);
#endif


#endif
}

#ifdef EDITOR
void Directx12Framework::CleanWindow()
{
#ifdef _WIN32
    D3D12_CPU_DESCRIPTOR_HANDLE currentRtvHandle(rtvHeap->GetCPUDescriptorHandleForHeapStart());
    SIZE_T rtvDescriptorIncrement = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
    currentRtvHandle.ptr += swapChain->GetCurrentBackBufferIndex() * rtvDescriptorIncrement;

    float clearColors[] = { 0, 1, 0, 0 };
    commandList->ClearRenderTargetView(currentRtvHandle, clearColors, 0, nullptr);
#endif
}
#endif


void Directx12Framework::SwapWindow()
{
#ifdef _WIN32
    commandList->Close();
    ID3D12CommandList* lists[] = { commandList };
    commandQueue->ExecuteCommandLists(_countof(lists), lists);
    swapChain->Present(1, 0);
#endif
}

void Directx12Framework::Cleanup()
{
#ifdef EDITOR
    ImGui_ImplDX12_Shutdown();
#endif
}

void Directx12Framework::OnSdlSetup()
{
}