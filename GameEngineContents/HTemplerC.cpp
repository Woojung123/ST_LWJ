

#include "PreCompile.h"
#include "HTemplerC.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"Sunken.h"

HTemplerC::HTemplerC()
	: Speed(50.0f)
	, Renderer(nullptr)
	, Reach(150.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.4f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, m_Dir({ 0 })
{
}

HTemplerC::~HTemplerC()
{
}




void HTemplerC::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 50.f,50.f,1.f });
		GetTransform().SetWorldPosition({ -990.f,310.f,0.f });


		Renderer->CreateFrameAnimationFolder("MarineAttack0", FrameAnimation_DESC("MarineAttack0", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack1", FrameAnimation_DESC("MarineAttack1", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack2", FrameAnimation_DESC("MarineAttack2", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack3", FrameAnimation_DESC("MarineAttack3", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack4", FrameAnimation_DESC("MarineAttack4", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack5", FrameAnimation_DESC("MarineAttack5", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack6", FrameAnimation_DESC("MarineAttack6", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack7", FrameAnimation_DESC("MarineAttack7", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack8", FrameAnimation_DESC("MarineAttack8", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack9", FrameAnimation_DESC("MarineAttack9", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack10", FrameAnimation_DESC("MarineAttack10", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack11", FrameAnimation_DESC("MarineAttack11", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack12", FrameAnimation_DESC("MarineAttack12", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack13", FrameAnimation_DESC("MarineAttack13", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack14", FrameAnimation_DESC("MarineAttack14", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack15", FrameAnimation_DESC("MarineAttack15", 0.1f));


		Renderer->ChangeFrameAnimation("MarineAttack0");


	}
}

void HTemplerC::Update(float _DeltaTime)
{
	//Renderer->ChangeFrameAnimation("DragonAttack15");
	std::list<GameEngineActor*> Group = GetLevel()->GetGroup(OBJECTORDER::Monster);

	int Monsize = (int)(Group.size());
	int MonCount = 0;

	auto	iter = Group.begin();
	auto	iterEnd = Group.end();

	for (; iter != iterEnd; ++iter)
	{
		GameEngineActor* TarGet = (*iter);
		float4 TarGetPos = TarGet->GetTransform().GetWorldPosition();
		float4 MyPos = GetTransform().GetWorldPosition();
		float4 Dist = MyPos - TarGetPos;
		float MonLen = Dist.Length();

		++MonCount;

		if (MonLen <= Reach)
		{

			m_Dir = (TarGetPos - MyPos);
			m_Dir.Normalize();

			ChangeAni(TarGetPos, MyPos);




			AttTime += _DeltaTime;

			if (AttTime >= AttTimeMax)
			{
				TestUni = GetLevel()->CreateActor<Sunken>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(TarGetPos);
				AttTime -= AttTimeMax;
				TestUni->TarGet = TarGet;
			}

			break;

		}


		if (MonCount == Monsize)
		{
			Renderer->ChangeFrameAnimation("MarineAttack0");
			AttTime = 0.f;
		}


	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });




}

void HTemplerC::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("MarineAttack12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack15");
	}


}
