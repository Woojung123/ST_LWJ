

#include "PreCompile.h"
#include "SingleButton.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

SingleButton::SingleButton()
{
}

SingleButton::~SingleButton()
{
}


void SingleButton::Start()
{

	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->GetTransform().SetLocalScale({ 216.f,136.f,1.f });
	Renderer->GetTransform().SetLocalPosition({ -250.f,150.f,10.f });
	Renderer->CreateFrameAnimationFolder("SingleButton", FrameAnimation_DESC("MenuSinglePlayerCheck0", 0.1f));
	Renderer->ChangeFrameAnimation("SingleButton");



}

void SingleButton::Update(float _DeltaTime)
{



}