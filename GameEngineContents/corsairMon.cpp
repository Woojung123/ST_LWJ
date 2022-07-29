
#include "PreCompile.h"
#include "corsairMon.h"
#include "StageMain.h"
#include "ProDeath.h"


//#include "GlobalContentsValue.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>

corsairMon::corsairMon()
	: Speed(100.0f)//100
	, Renderer(nullptr)
	, DeathEff(nullptr)
	
{
}

corsairMon::~corsairMon()
{
}



void corsairMon::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 60.f,60.f,1.f });
		GetTransform().SetWorldPosition({ -1348.f,617.f,0.f });

		Renderer->CreateFrameAnimationFolder("corsairMoveD", FrameAnimation_DESC("corsairMoveD", 0.1f, true));
		Renderer->CreateFrameAnimationFolder("corsairMoveL", FrameAnimation_DESC("corsairMoveL", 0.1f, true));
		Renderer->CreateFrameAnimationFolder("corsairMoveR", FrameAnimation_DESC("corsairMoveR", 0.1f, true));
		Renderer->CreateFrameAnimationFolder("corsairMoveU", FrameAnimation_DESC("corsairMoveU", 0.1f, true));


		Renderer->ChangeFrameAnimation("corsairMoveD");

	}


}

void corsairMon::Update(float _DeltaTime)
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



void corsairMon::Move(float _DeltaTime)
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

void corsairMon::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;


	if (m_fAngle >= 45.f && m_fAngle < 135.f)
	{
		Renderer->ChangeFrameAnimation("corsairMoveU");
	}
	else if (m_fAngle >= 135.f && m_fAngle <= 225.f)
	{
		Renderer->ChangeFrameAnimation("corsairMoveL");
	}
	else if (m_fAngle >= 225.f && m_fAngle <= 315.f)
	{
		Renderer->ChangeFrameAnimation("corsairMoveD");
	}
	else if (m_fAngle >= 315.f || m_fAngle <= 45.f)
	{
		Renderer->ChangeFrameAnimation("corsairMoveR");
	}



}
