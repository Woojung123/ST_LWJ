#include "PreCompile.h"
#include "LoginUI.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>

LoginUI::LoginUI()
	: TimeAngle(0.0f),
	Deathcheck(false)
{
}

LoginUI::~LoginUI()
{
}


void LoginUI::Start()
{
	// 800 600
	// GetTransform().SetLocalPosition({ 0, 200, 0 });

	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 800, 600, 100 });

		Renderer->GetTransform().SetLocalPosition({ 0.f,0.f,-100.f });
		Renderer->SetTexture("Logo.png");
	}

	
}

void LoginUI::Update(float _DeltaTime)
{
	
	if (!Deathcheck)
	{
		Deathcheck = true;
		Death(2.f);
	}
	

}

void LoginUI::End()
{
	int a = 0;
}