
#include "PreCompile.h"
#include "StartButton.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

StartButton::StartButton()
{
}

StartButton::~StartButton()
{
}


void StartButton::Start()
{

	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->GetTransform().SetLocalScale({ 216.f,136.f,1.f });
	Renderer->GetTransform().SetLocalPosition({200.f,150.f,10.f});
	Renderer->CreateFrameAnimationFolder("StartButton", FrameAnimation_DESC("MenuExitCheck", 0.1f));
	Renderer->ChangeFrameAnimation("StartButton");

	

}

void StartButton::Update(float _DeltaTime)
{


	
		
		

}