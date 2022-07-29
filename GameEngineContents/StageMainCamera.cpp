

#include "PreCompile.h"
#include "StageMainCamera.h"
#include <GameEngineBase/GameEngineInput.h>


StageMainCamera::StageMainCamera()
	: Speed(750.0f)
{
}

StageMainCamera::~StageMainCamera()
{
}


void StageMainCamera::Start()
{

	


	GetTransform().SetWorldMove({-1000.f,350.f,0.f});
}

void StageMainCamera::Update(float _DeltaTime)
{
	
	if (true == GetLevel()->GetMainCameraActor()->IsFreeCameraMode())
	{
		return;
	}

	float MouseScreenPosX = GetLevel()->GetMainCamera()->GetScreenPosition().x;
	float MouseScreenPosY = GetLevel()->GetMainCamera()->GetScreenPosition().y;


	//카메라 이동
	{
		if (MouseScreenPosX >= 800.f)
		{
			GetTransform().SetWorldMove(GetTransform().GetRightVector() * Speed * _DeltaTime);
		}


		if (MouseScreenPosX <= 0.f)
		{
			GetTransform().SetWorldMove(GetTransform().GetLeftVector() * Speed * _DeltaTime);
		}

		if (MouseScreenPosY >= 600.f)
		{
			GetTransform().SetWorldMove(GetTransform().GetDownVector() * Speed * _DeltaTime);
		}


		if (MouseScreenPosY <= 0.f)
		{
			GetTransform().SetWorldMove(GetTransform().GetUpVector() * Speed * _DeltaTime);
		}

	}


	MouseScreenPosX = GetLevel()->GetMainCamera()->GetMouseWorldPosition().x;
	MouseScreenPosY = GetLevel()->GetMainCamera()->GetMouseWorldPosition().y;

	std::string A = std::to_string(MouseScreenPosX);
	std::string B = std::to_string(MouseScreenPosY);

	A += " X";
	B += " Y";
	GameEngineDebug::OutPutString(A);
	GameEngineDebug::OutPutString(B);
	////화면 고정

	{
		float4 WorldPos = GetTransform().GetWorldPosition();

		if (WorldPos.x >= 1050)
		{
			GetTransform().SetWorldPosition({ 1050.f,WorldPos.y,WorldPos.z });
		}
		WorldPos = GetTransform().GetWorldPosition();
		if (WorldPos.x <= -1050.f)
		{
			GetTransform().SetWorldPosition({ -1050.f,WorldPos.y,WorldPos.z });
		}
		WorldPos = GetTransform().GetWorldPosition();
		if (WorldPos.y >= 400.f)
		{
			GetTransform().SetWorldPosition({ WorldPos.x,400.f,WorldPos.z });
		}
		WorldPos = GetTransform().GetWorldPosition();
		if (WorldPos.y <= -400.f)
		{
			GetTransform().SetWorldPosition({ WorldPos.x,-400.f,WorldPos.z });
		}

	}

	GetLevel()->GetMainCameraActorTransform().SetLocalPosition(GetTransform().GetLocalPosition());
}