
#include "PreCompile.h"
#include "LogoBack.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>

LogoBack::LogoBack()
	: TimeAngle(0.0f),
	Deathcheck(false)
{
}

LogoBack::~LogoBack()
{
}


void LogoBack::Start()
{
	// 800 600
	// GetTransform().SetLocalPosition({ 0, 200, 0 });

	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 800, 600, 100 });
		Renderer->SetTexture("menubackground.png");
	}


}

void LogoBack::Update(float _DeltaTime)
{

}

void LogoBack::End()
{
	
}