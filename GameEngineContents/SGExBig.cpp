
#include "PreCompile.h"
#include "SGExBig.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
SGExBig::SGExBig()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

SGExBig::~SGExBig()
{
	Death();
}

void SGExBig::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void SGExBig::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 252.f,200.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("Explosion_L", FrameAnimation_DESC("Explosion_L", 0.05f));
		Renderer->ChangeFrameAnimation("Explosion_L");
		Renderer->AnimationBindEnd("Explosion_L", &SGExBig::AttEnd, this);
	}
}

void SGExBig::Update(float _DeltaTime)
{

	if (BAniChange)
		Death();


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -50.f, WorldPos.w });

}