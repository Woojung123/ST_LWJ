

#include "PreCompile.h"
#include "SGExMid.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
SGExMid::SGExMid()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

SGExMid::~SGExMid()
{
	Death();
}

void SGExMid::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void SGExMid::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 200.f,200.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("Explosion_M", FrameAnimation_DESC("Explosion_M", 0.05f));
		Renderer->ChangeFrameAnimation("Explosion_M");
		Renderer->AnimationBindEnd("Explosion_M", &SGExMid::AttEnd, this);
	}
}

void SGExMid::Update(float _DeltaTime)
{

	if (BAniChange)
		Death();


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -50.f, WorldPos.w });

}