
#include "PreCompile.h"
#include "ScoutMon.h"
#include "StageMain.h"
#include "ProDeath.h"


#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>

ScoutMon::ScoutMon()
	: Speed(100.0f)//100
	, Renderer(nullptr)
	, DeathEff(nullptr)
	
{
}

ScoutMon::~ScoutMon()
{
}



void ScoutMon::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 72.f,72.f,1.f });
		GetTransform().SetWorldPosition({ -1348.f,617.f,0.f });

		Renderer->CreateFrameAnimationFolder("ScoutMoveD", FrameAnimation_DESC("ScoutMoveD", 0.1f, true));
		Renderer->CreateFrameAnimationFolder("ScoutMoveL", FrameAnimation_DESC("ScoutMoveL", 0.1f, true));
		Renderer->CreateFrameAnimationFolder("ScoutMoveR", FrameAnimation_DESC("ScoutMoveR", 0.1f, true));
		Renderer->CreateFrameAnimationFolder("ScoutMoveU", FrameAnimation_DESC("ScoutMoveU", 0.1f, true));


		Renderer->ChangeFrameAnimation("ScoutMoveD");

	}



}

void ScoutMon::Update(float _DeltaTime)
{

	if (m_Info.m_Hp <= 0)
	{
		DeathEff = GetLevel()->CreateActor<ProDeath>(OBJECTORDER::Effect);
		DeathEff->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
		Death();
	}

	Move(_DeltaTime);

	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -20.f, WorldPos.w });

}

void ScoutMon::Move(float _DeltaTime)
{
	float4 GoPoint;
	auto	iter = CheckPoint.begin();
	auto	iterEnd = CheckPoint.end();

	float4 WorldPos = GetTransform().GetWorldPosition();
	WorldPos.z = 1.f;
	for (; iter != iterEnd; ++iter)
	{

		if (iter->TurnCheck == true)
		{
			if ((int)(WorldPos.x + 3) > (int)(iter->TurnPoint.x) &&
				(int)(WorldPos.x - 3) < (int)(iter->TurnPoint.x)
				&& (int)(WorldPos.y - 3) < (int)(iter->TurnPoint.y)
				&& (int)(WorldPos.y + 3) > (int)(iter->TurnPoint.y))
			{
				iter->TurnCheck = false;

				if (iter->TurnPoint.x == -1105.f && iter->TurnPoint.y == 633.f)
				{

					m_Info.m_Hp = -1;
				}
				break;


			}
			else
			{
				GoPoint = iter->TurnPoint;
				break;
			}
		}




	}


	m_Dir = (GoPoint - WorldPos);
	m_Dir.Normalize();


	GetTransform().SetWorldMove(m_Dir * _DeltaTime * Speed);

	ChangeAni(GoPoint, WorldPos);





}

void ScoutMon::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;


	if (m_fAngle >= 45.f && m_fAngle < 135.f)
	{
		Renderer->ChangeFrameAnimation("ScoutMoveU");
	}
	else if (m_fAngle >= 135.f && m_fAngle <= 225.f)
	{
		Renderer->ChangeFrameAnimation("ScoutMoveL");
	}
	else if (m_fAngle >= 225.f && m_fAngle <= 315.f)
	{
		Renderer->ChangeFrameAnimation("ScoutMoveD");
	}
	else if (m_fAngle >= 315.f || m_fAngle <= 45.f)
	{
		Renderer->ChangeFrameAnimation("ScoutMoveR");
	}



}
