

#include "PreCompile.h"
#include "MutalEff.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
MutalEff::MutalEff()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

MutalEff::~MutalEff()
{
	Death();
}

void MutalEff::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void MutalEff::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("MutalDead0", FrameAnimation_DESC("MutalDead0", 0.05f));
		Renderer->ChangeFrameAnimation("MutalDead0");
		Renderer->AnimationBindEnd("MutalDead0", &MutalEff::AttEnd, this);
	}
}

void MutalEff::Update(float _DeltaTime)
{

	if (BAniChange)
		Death();


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -50.f, WorldPos.w });

}