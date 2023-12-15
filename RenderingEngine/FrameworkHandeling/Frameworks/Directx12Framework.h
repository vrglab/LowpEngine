/* ======================================================================================== */
/* LowpEngine - Rendering Engine C/C++ header file.										    */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <Core/Debugging/Debug.h>
#include <Core/Application/ApplicationInfo.h>

#include "RenderingEngine/FrameworkHandeling/Framework.h"

#include <SDL2/SDL.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include <iostream>

#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")

class Directx12Framework : Framework
{
private:
	ID3D12Device* device;
	ID3D12CommandQueue* commandQueue;
	IDXGISwapChain3* swapChain;
	IDXGIFactory4* dxgiFactory;
	ID3D12DescriptorHeap* rtvHeap;
	ID3D12Resource* renderTargets[2];
	ID3D12CommandAllocator* commandAllocator;
	ID3D12GraphicsCommandList* commandList;

public:
	void Init(Ref<ApplicationInfo>, SDL_Window*) override;
	void Tick() override;
	void SwapWindow() override;
	void Cleanup() override;
};

