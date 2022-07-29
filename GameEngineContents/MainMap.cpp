
#include "PreCompile.h"
#include "MainMap.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

MainMap::MainMap()
{
}
\
MainMap::~MainMap()
{
}


void MainMap::Start()
{

	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("Defen.png");
		Renderer->ScaleToTexture();
		
	}
	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos .x , WorldPos .y , 100.f, WorldPos.w });

	
}
void MainMap::Update(float _DeltaTime)
{
}