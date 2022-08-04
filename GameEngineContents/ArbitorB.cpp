
#include "PreCompile.h"
#include "ArbitorB.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"BloodBullet.h"

ArbitorB::ArbitorB()
	: Speed(50.0f)
	, Renderer(nullptr)
	, Reach(200.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.4f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, m_Dir({ 0 })
	, BAniChange(false)

{
}

ArbitorB::~ArbitorB()
{
}

void ArbitorB::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	Renderer->ChangeFrameAnimation("ArbitorMove12");

}


void ArbitorB::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 64.f,64.f,1.f });


		Renderer->CreateFrameAnimationFolder("ArbitorMove0", FrameAnimation_DESC("ArbitorMove0", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArbitorMove1", FrameAnimation_DESC("ArbitorMove1", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArbitorMove2", FrameAnimation_DESC("ArbitorMove2", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArbitorMove3", FrameAnimation_DESC("ArbitorMove3", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArbitorMove4", FrameAnimation_DESC("ArbitorMove4", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArbitorMove5", FrameAnimation_DESC("ArbitorMove5", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArbitorMove6", FrameAnimation_DESC("ArbitorMove6", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArbitorMove7", FrameAnimation_DESC("ArbitorMove7", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArbitorMove8", FrameAnimation_DESC("ArbitorMove8", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArbitorMove9", FrameAnimation_DESC("ArbitorMove9", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArbitorMove10", FrameAnimation_DESC("ArbitorMove10", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArbitorMove11", FrameAnimation_DESC("ArbitorMove11", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArbitorMove12", FrameAnimation_DESC("ArbitorMove12", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArbitorMove13", FrameAnimation_DESC("ArbitorMove13", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArbitorMove14", FrameAnimation_DESC("ArbitorMove14", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArbitorMove15", FrameAnimation_DESC("ArbitorMove15", 0.1f));
		

		Renderer->ChangeFrameAnimation("ArbitorMove12");


	}


	{
		BiconRenderer = CreateComponent<GameEngineTextureRenderer>();
		BiconRenderer->SetTexture("beacon.png");
		BiconRenderer->ScaleToTexture();
		float4 RenderWorldPos = BiconRenderer->GetTransform().GetWorldPosition();
		BiconRenderer->GetTransform().SetWorldPosition({ RenderWorldPos.x - 5.f, RenderWorldPos.y - 5.f , 1.f });
	}


}

void ArbitorB::Update(float _DeltaTime)
{
	//Renderer->ChangeFrameAnimation("DragonAttack15");
	std::list<GameEngineActor*> Group = GetLevel()->GetGroup(OBJECTORDER::Monster);

	int Monsize = (int)Group.size();
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

			
			if (AttTime >= 5.f)
			{
				AttTime -= 5.f;
				
				BAniChange = false;

				TestUni = GetLevel()->CreateActor<BloodBullet>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(MyPos);
				TestUni->SetTarGet(TarGet);



			}


			break;
		}


		if (MonCount == Monsize)
		{
			
			AttTime = 0.f;
		}


	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });




}

void ArbitorB::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("ArbitorMove0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("ArbitorMove1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("ArbitorMove2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("ArbitorMove3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("ArbitorMove4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("ArbitorMove5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("ArbitorMove6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("ArbitorMove7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("ArbitorMove8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("ArbitorMove9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("ArbitorMove10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("ArbitorMove11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("ArbitorMove12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("ArbitorMove13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("ArbitorMove14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("ArbitorMove15");
	}


}
