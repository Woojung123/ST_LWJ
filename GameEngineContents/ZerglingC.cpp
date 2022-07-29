
#include "PreCompile.h"
#include "ZerglingC.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"Sunken.h"

ZerglingC::ZerglingC()
	: Speed(50.0f)
	, Renderer(nullptr)
	, Reach(150.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.4f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

ZerglingC::~ZerglingC()
{
}


void ZerglingC::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	Renderer->ChangeFrameAnimation("zerglingMove12");

}



void ZerglingC::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });
		

		Renderer->CreateFrameAnimationFolder("zerglingAttack0", FrameAnimation_DESC("zerglingAttack0", 0.1f));
		Renderer->CreateFrameAnimationFolder("zerglingAttack1", FrameAnimation_DESC("zerglingAttack1", 0.1f));
		Renderer->CreateFrameAnimationFolder("zerglingAttack2", FrameAnimation_DESC("zerglingAttack2", 0.1f));
		Renderer->CreateFrameAnimationFolder("zerglingAttack3", FrameAnimation_DESC("zerglingAttack3", 0.1f));
		Renderer->CreateFrameAnimationFolder("zerglingAttack4", FrameAnimation_DESC("zerglingAttack4", 0.1f));
		Renderer->CreateFrameAnimationFolder("zerglingAttack5", FrameAnimation_DESC("zerglingAttack5", 0.1f));
		Renderer->CreateFrameAnimationFolder("zerglingAttack6", FrameAnimation_DESC("zerglingAttack6", 0.1f));
		Renderer->CreateFrameAnimationFolder("zerglingAttack7", FrameAnimation_DESC("zerglingAttack7", 0.1f));
		Renderer->CreateFrameAnimationFolder("zerglingAttack8", FrameAnimation_DESC("zerglingAttack8", 0.1f));
		Renderer->CreateFrameAnimationFolder("zerglingAttack9", FrameAnimation_DESC("zerglingAttack9", 0.1f));
		Renderer->CreateFrameAnimationFolder("zerglingAttack10", FrameAnimation_DESC("zerglingAttack10", 0.1f));
		Renderer->CreateFrameAnimationFolder("zerglingAttack11", FrameAnimation_DESC("zerglingAttack11", 0.1f));
		Renderer->CreateFrameAnimationFolder("zerglingAttack12", FrameAnimation_DESC("zerglingAttack12", 0.1f));
		Renderer->CreateFrameAnimationFolder("zerglingAttack13", FrameAnimation_DESC("zerglingAttack13", 0.1f));
		Renderer->CreateFrameAnimationFolder("zerglingAttack14", FrameAnimation_DESC("zerglingAttack14", 0.1f));
		Renderer->CreateFrameAnimationFolder("zerglingAttack15", FrameAnimation_DESC("zerglingAttack15", 0.1f));

		Renderer->CreateFrameAnimationFolder("zerglingMove12", FrameAnimation_DESC("zerglingMove12", 0.1f));

		Renderer->ChangeFrameAnimation("zerglingMove12");


		Renderer->AnimationBindEnd("zerglingAttack0", &ZerglingC::AttEnd, this);
		Renderer->AnimationBindEnd("zerglingAttack1", &ZerglingC::AttEnd, this);
		Renderer->AnimationBindEnd("zerglingAttack2", &ZerglingC::AttEnd, this);
		Renderer->AnimationBindEnd("zerglingAttack3", &ZerglingC::AttEnd, this);
		Renderer->AnimationBindEnd("zerglingAttack4", &ZerglingC::AttEnd, this);
		Renderer->AnimationBindEnd("zerglingAttack5", &ZerglingC::AttEnd, this);
		Renderer->AnimationBindEnd("zerglingAttack6", &ZerglingC::AttEnd, this);
		Renderer->AnimationBindEnd("zerglingAttack7", &ZerglingC::AttEnd, this);
		Renderer->AnimationBindEnd("zerglingAttack8", &ZerglingC::AttEnd, this);
		Renderer->AnimationBindEnd("zerglingAttack9", &ZerglingC::AttEnd, this);
		Renderer->AnimationBindEnd("zerglingAttack10", &ZerglingC::AttEnd, this);
		Renderer->AnimationBindEnd("zerglingAttack11", &ZerglingC::AttEnd, this);
		Renderer->AnimationBindEnd("zerglingAttack12", &ZerglingC::AttEnd, this);
		Renderer->AnimationBindEnd("zerglingAttack13", &ZerglingC::AttEnd, this);
		Renderer->AnimationBindEnd("zerglingAttack14", &ZerglingC::AttEnd, this);
		Renderer->AnimationBindEnd("zerglingAttack15", &ZerglingC::AttEnd, this);

	}
}

void ZerglingC::Update(float _DeltaTime)
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

			if (!BAniChange)
			{
				m_Dir = (TarGetPos - MyPos);
				m_Dir.Normalize();

				ChangeAni(TarGetPos, MyPos);
				BAniChange = true;
			}

			if (AttCheck)
			{

				AttCheck = false;

				BAniChange = false;

				TestUni = GetLevel()->CreateActor<Sunken>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(TarGetPos);
				TestUni->TarGet = TarGet;
			}
			break;
		}


		if (MonCount == Monsize)
		{
			AttCheck = false;
			BAniChange = false;
			Renderer->ChangeFrameAnimation("zerglingMove12");
			AttTime = 0.f;
		}


	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });




}

void ZerglingC::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("zerglingAttack0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("zerglingAttack1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("zerglingAttack2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("zerglingAttack3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("zerglingAttack4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("zerglingAttack5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("zerglingAttack6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("zerglingAttack7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("zerglingAttack8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("zerglingAttack9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("zerglingAttack10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("zerglingAttack11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("zerglingAttack12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("zerglingAttack13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("zerglingAttack14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("zerglingAttack15");
	}


}
