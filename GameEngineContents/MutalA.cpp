

#include "PreCompile.h"
#include "MutalA.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"mutalBullet.h"

MutalA::MutalA()
	: Speed(50.0f)
	, Renderer(nullptr)
	, Reach(250.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.4f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, m_Dir({ 0 })
	, BAniChange(false)
	, AttCount(0)
	, AttCountMax(3)
{
}

MutalA::~MutalA()
{
}


void MutalA::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	//Renderer->ChangeFrameAnimation("GardianMove12");
	BAniChange = false;
}



void MutalA::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 96.f,96.f,1.f });
		GetTransform().SetWorldPosition({ -990.f,310.f,0.f });


		Renderer->CreateFrameAnimationFolder("mutalMove0", FrameAnimation_DESC("mutalMove0", 0.1f));
		Renderer->CreateFrameAnimationFolder("mutalMove1", FrameAnimation_DESC("mutalMove1", 0.1f));
		Renderer->CreateFrameAnimationFolder("mutalMove2", FrameAnimation_DESC("mutalMove2", 0.1f));
		Renderer->CreateFrameAnimationFolder("mutalMove3", FrameAnimation_DESC("mutalMove3", 0.1f));
		Renderer->CreateFrameAnimationFolder("mutalMove4", FrameAnimation_DESC("mutalMove4", 0.1f));
		Renderer->CreateFrameAnimationFolder("mutalMove5", FrameAnimation_DESC("mutalMove5", 0.1f));
		Renderer->CreateFrameAnimationFolder("mutalMove6", FrameAnimation_DESC("mutalMove6", 0.1f));
		Renderer->CreateFrameAnimationFolder("mutalMove7", FrameAnimation_DESC("mutalMove7", 0.1f));
		Renderer->CreateFrameAnimationFolder("mutalMove8", FrameAnimation_DESC("mutalMove8", 0.1f));
		Renderer->CreateFrameAnimationFolder("mutalMove9", FrameAnimation_DESC("mutalMove9", 0.1f));
		Renderer->CreateFrameAnimationFolder("mutalMove10", FrameAnimation_DESC("mutalMove10", 0.1f));
		Renderer->CreateFrameAnimationFolder("mutalMove11", FrameAnimation_DESC("mutalMove11", 0.1f));
		Renderer->CreateFrameAnimationFolder("mutalMove12", FrameAnimation_DESC("mutalMove12", 0.1f));
		Renderer->CreateFrameAnimationFolder("mutalMove13", FrameAnimation_DESC("mutalMove13", 0.1f));
		Renderer->CreateFrameAnimationFolder("mutalMove14", FrameAnimation_DESC("mutalMove14", 0.1f));
		Renderer->CreateFrameAnimationFolder("mutalMove15", FrameAnimation_DESC("mutalMove15", 0.1f));


		Renderer->ChangeFrameAnimation("mutalMove12");


		Renderer->AnimationBindEnd("mutalMove0", &MutalA::AttEnd, this);
		Renderer->AnimationBindEnd("mutalMove1", &MutalA::AttEnd, this);
		Renderer->AnimationBindEnd("mutalMove2", &MutalA::AttEnd, this);
		Renderer->AnimationBindEnd("mutalMove3", &MutalA::AttEnd, this);
		Renderer->AnimationBindEnd("mutalMove4", &MutalA::AttEnd, this);
		Renderer->AnimationBindEnd("mutalMove5", &MutalA::AttEnd, this);
		Renderer->AnimationBindEnd("mutalMove6", &MutalA::AttEnd, this);
		Renderer->AnimationBindEnd("mutalMove7", &MutalA::AttEnd, this);
		Renderer->AnimationBindEnd("mutalMove8", &MutalA::AttEnd, this);
		Renderer->AnimationBindEnd("mutalMove9", &MutalA::AttEnd, this);
		Renderer->AnimationBindEnd("mutalMove10", &MutalA::AttEnd, this);
		Renderer->AnimationBindEnd("mutalMove11", &MutalA::AttEnd, this);
		Renderer->AnimationBindEnd("mutalMove12", &MutalA::AttEnd, this);
		Renderer->AnimationBindEnd("mutalMove13", &MutalA::AttEnd, this);
		Renderer->AnimationBindEnd("mutalMove14", &MutalA::AttEnd, this);
		Renderer->AnimationBindEnd("mutalMove15", &MutalA::AttEnd, this);



	}



	{

		AuraRenderer = CreateComponent<GameEngineTextureRenderer>();
		AuraRenderer->CreateFrameAnimationFolder("aulora0", FrameAnimation_DESC("aulora0", 0.1f));
		AuraRenderer->ChangeFrameAnimation("aulora0");
		AuraRenderer->GetTransform().SetLocalScale({ 120.f,120.f,1.f });
		float4 RenderWorldPos = AuraRenderer->GetTransform().GetWorldPosition();

		AuraRenderer->GetTransform().SetWorldPosition(RenderWorldPos);


	}


	{
		BiconRenderer = CreateComponent<GameEngineTextureRenderer>();
		BiconRenderer->CreateFrameAnimationFolder("pool", FrameAnimation_DESC("pool", 0.1f));
		BiconRenderer->ChangeFrameAnimation("pool");
		BiconRenderer->GetTransform().SetLocalScale({ 96.f,128.f,1.f });
		float4 RenderWorldPos = BiconRenderer->GetTransform().GetWorldPosition();
		BiconRenderer->GetTransform().SetWorldPosition({ RenderWorldPos.x - 5.f, RenderWorldPos.y - 5.f , 1.f });
	
	
	}



	//{

	//	AuraRenderer = CreateComponent<GameEngineTextureRenderer>();
	//	AuraRenderer->CreateFrameAnimationFolder("Maelstorm", FrameAnimation_DESC("Maelstorm", 0.1f));
	//	AuraRenderer->ChangeFrameAnimation("Maelstorm");
	//	AuraRenderer->GetTransform().SetLocalScale({ 64.f,64.f,1.f });
	//	AuraRenderer->GetColorData().MulColor.a = 0.6f;
	//	float4 RenderWorldPos = AuraRenderer->GetTransform().GetWorldPosition();

	//	AuraRenderer->GetTransform().SetWorldPosition(RenderWorldPos);


	//}

}

void MutalA::Update(float _DeltaTime)
{
	//Renderer->ChangeFrameAnimation("DragonAttack15");
	std::list<GameEngineActor*> Group = GetLevel()->GetGroup(OBJECTORDER::Monster);

	int Monsize = (int)(Group.size());
	int MonCount = 0;
	AttCount = 0;
	AttCountMax = 5;
	auto	iter = Group.begin();
	auto	iterEnd = Group.end();
	GameEngineActor* TarGet = nullptr;
	GameEngineActor* TarGet2 = nullptr;
	GameEngineActor* TarGet3 = nullptr;
	GameEngineActor* TarGet4 = nullptr;
	for (; iter != iterEnd; ++iter)
	{
		TarGet = (*iter);

		float4 TarGetPos = TarGet->GetTransform().GetWorldPosition();
		float4 MyPos = GetTransform().GetWorldPosition();
		float4 Dist = MyPos - TarGetPos;
		float MonLen = Dist.Length();

		++MonCount;

		if (MonLen <= Reach)
		{
			++AttCount;

			if (AttCount == 1)
			{
				TarGet2 = TarGet;
			}
			else if (AttCount == 2)
			{
				TarGet3 = TarGet;
			}
			else if (AttCount == 3)
			{
				TarGet4 = TarGet;
			}

			if (!BAniChange)
			{
				m_Dir = (TarGetPos - MyPos);
				m_Dir.Normalize();

				ChangeAni(TarGetPos, MyPos);
				BAniChange = true;
			}


			if (AttCheck)
			{

				if (AttCount == 3)
				{
					TestUni = GetLevel()->CreateActor<mutalBullet>(OBJECTORDER::Bullet);
					TestUni->GetTransform().SetWorldPosition(MyPos);
					TestUni->SetTarGet(TarGet);
					TestUni->m_Info.Dammage = 120;

					TestUni->TarGet = TarGet2;
					TestUni->TarGet2 = TarGet3;
					TestUni->TarGet3 = TarGet4;
				}
				
			}

			if (AttCountMax >= (Monsize - 1))
			{
				AttCountMax = (Monsize - 1);
			}

			if (AttCount >= AttCountMax)
			{
				AttCheck = false;
				AttCount = 0;
				break;
			}


		}


		if (MonCount == Monsize)
		{
			AttCheck = false;
			//Renderer->ChangeFrameAnimation("GardianMove12");
			AttTime = 0.f;
			AttCount = 0;
			AttCountMax = 5;
		}


	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });




}

void MutalA::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("mutalMove0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("mutalMove1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("mutalMove2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("mutalMove3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("mutalMove4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("mutalMove5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("mutalMove6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("mutalMove7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("mutalMove8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("mutalMove9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("mutalMove10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("mutalMove11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("mutalMove12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("mutalMove13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("mutalMove14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("mutalMove15");
	}


}
