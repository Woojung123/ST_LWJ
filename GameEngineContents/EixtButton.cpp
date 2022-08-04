

#include "PreCompile.h"
#include "EixtButton.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

EixtButton::EixtButton()
{
}

EixtButton::~EixtButton()
{
}


void EixtButton::Start()
{

	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->GetTransform().SetLocalScale({ 216.f,136.f,1.f });
	Renderer->GetTransform().SetLocalPosition({ 200.f,-200.f,10.f });
	Renderer->CreateFrameAnimationFolder("ExitButton", FrameAnimation_DESC("MenuEditor0", 0.1f));
	Renderer->ChangeFrameAnimation("ExitButton");



}

void EixtButton::Update(float _DeltaTime)
{



}