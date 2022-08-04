
#include "PreCompile.h"
#include "SGExSmall.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
SGExSmall::SGExSmall()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

SGExSmall::~SGExSmall()
{
	Death();
}

void SGExSmall::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void SGExSmall::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("Explosion_S", FrameAnimation_DESC("Explosion_S", 0.05f));
		Renderer->ChangeFrameAnimation("Explosion_S");
		Renderer->AnimationBindEnd("Explosion_S", &SGExSmall::AttEnd, this);
	}
}

void SGExSmall::Update(float _DeltaTime)
{

	if (BAniChange)
		Death();


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -50.f, WorldPos.w });

}