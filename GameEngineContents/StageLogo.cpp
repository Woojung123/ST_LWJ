
#include "PreCompile.h"
#include "StageLogo.h"
#include "LoginUI.h"
#include "LogoBack.h"
#include "StartButton.h"
#include "EixtButton.h"
#include "SingleButton.h"


#include "Enums.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineBase/GameEngineInput.h>

StageLogo::StageLogo()
{
}

StageLogo::~StageLogo()
{
}


void StageLogo::Start()
{
	if (false == GameEngineInput::GetInst()->IsKey("LevelChange"))
	{
		GameEngineInput::GetInst()->CreateKey("LevelChange", 'P');
	}


	//GameEngineCameraActor* CameraActor = CreateActor<GameEngineCameraActor>();
	//CameraActor->GetTransform().SetLocalPosition({ 0.0f, 0.0f, -100.0f });
	//CameraActor->GetCameraComponent()->SetProjectionMode(CAMERAPROJECTIONMODE::Orthographic);


	

	CreateActor<EixtButton>(GameObjectGroup::UI);
	
	CreateActor<SingleButton>(GameObjectGroup::UI);



	
	
	CreateActor<LogoBack>(GameObjectGroup::UI);

	CreateActor<StartButton>(GameObjectGroup::UI);

	CreateActor<LoginUI>(GameObjectGroup::UI);

}

void StageLogo::Update(float _DeltaTime)
{
	if (true == GameEngineInput::GetInst()->IsDown("LevelChange"))
	{
		GEngine::ChangeLevel("Play");
	}
}

void StageLogo::End()
{
}