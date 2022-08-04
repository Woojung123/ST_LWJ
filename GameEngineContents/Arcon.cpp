

#include "PreCompile.h"
#include "Arcon.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"ArconBul.h"

Arcon::Arcon()
	: Speed(50.0f)
	, Renderer(nullptr)
	, BackRenderer(nullptr)
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

Arcon::~Arcon()
{
}


void Arcon::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	//Renderer->ChangeFrameAnimation("GardianMove12");
	BAniChange = false;
}



void Arcon::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 120.f,120.f,1.f });
		GetTransform().SetWorldPosition({ -990.f,310.f,0.f });
		//Renderer->GetTransform().SetLocalPosition({ 0.f,0.f,-2.f });
		Renderer->GetTransform().SetLocalPosition({ 0.f,0.f,-5.f });
		Renderer->CreateFrameAnimationFolder("ArchonAttack0", FrameAnimation_DESC("ArchonAttack0", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArchonAttack1", FrameAnimation_DESC("ArchonAttack1", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArchonAttack2", FrameAnimation_DESC("ArchonAttack2", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArchonAttack3", FrameAnimation_DESC("ArchonAttack3", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArchonAttack4", FrameAnimation_DESC("ArchonAttack4", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArchonAttack5", FrameAnimation_DESC("ArchonAttack5", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArchonAttack6", FrameAnimation_DESC("ArchonAttack6", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArchonAttack7", FrameAnimation_DESC("ArchonAttack7", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArchonAttack8", FrameAnimation_DESC("ArchonAttack8", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArchonAttack9", FrameAnimation_DESC("ArchonAttack9", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArchonAttack10", FrameAnimation_DESC("ArchonAttack10", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArchonAttack11", FrameAnimation_DESC("ArchonAttack11", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArchonAttack12", FrameAnimation_DESC("ArchonAttack12", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArchonAttack13", FrameAnimation_DESC("ArchonAttack13", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArchonAttack14", FrameAnimation_DESC("ArchonAttack14", 0.1f));
		Renderer->CreateFrameAnimationFolder("ArchonAttack15", FrameAnimation_DESC("ArchonAttack15", 0.1f));

		Renderer->CreateFrameAnimationFolder("ArchonMove12", FrameAnimation_DESC("ArchonMove12", 0.1f));

		Renderer->ChangeFrameAnimation("ArchonMove12");


		Renderer->AnimationBindEnd("ArchonAttack0", &Arcon::AttEnd, this);
		Renderer->AnimationBindEnd("ArchonAttack1", &Arcon::AttEnd, this);
		Renderer->AnimationBindEnd("ArchonAttack2", &Arcon::AttEnd, this);
		Renderer->AnimationBindEnd("ArchonAttack3", &Arcon::AttEnd, this);
		Renderer->AnimationBindEnd("ArchonAttack4", &Arcon::AttEnd, this);
		Renderer->AnimationBindEnd("ArchonAttack5", &Arcon::AttEnd, this);
		Renderer->AnimationBindEnd("ArchonAttack6", &Arcon::AttEnd, this);
		Renderer->AnimationBindEnd("ArchonAttack7", &Arcon::AttEnd, this);
		Renderer->AnimationBindEnd("ArchonAttack8", &Arcon::AttEnd, this);
		Renderer->AnimationBindEnd("ArchonAttack9", &Arcon::AttEnd, this);
		Renderer->AnimationBindEnd("ArchonAttack10", &Arcon::AttEnd, this);
		Renderer->AnimationBindEnd("ArchonAttack11", &Arcon::AttEnd, this);
		Renderer->AnimationBindEnd("ArchonAttack12", &Arcon::AttEnd, this);
		Renderer->AnimationBindEnd("ArchonAttack13", &Arcon::AttEnd, this);
		Renderer->AnimationBindEnd("ArchonAttack14", &Arcon::AttEnd, this);
		Renderer->AnimationBindEnd("ArchonAttack15", &Arcon::AttEnd, this);



	}



	{

		AuraRenderer = CreateComponent<GameEngineTextureRenderer>();
		AuraRenderer->CreateFrameAnimationFolder("aulora0", FrameAnimation_DESC("aulora0", 0.1f));
		AuraRenderer->ChangeFrameAnimation("aulora0");
		AuraRenderer->GetTransform().SetLocalScale({ 120.f,120.f,1.f });
		//float4 RenderWorldPos = AuraRenderer->GetTransform().GetWorldPosition();
		AuraRenderer->GetTransform().SetLocalPosition({ 0.f,0.f,-3.f });
		//AuraRenderer->GetTransform().SetWorldPosition(RenderWorldPos);


	}

	//{

	//	AuraRenderer2 = CreateComponent<GameEngineTextureRenderer>();
	//	AuraRenderer2->CreateFrameAnimationFolder("Maelstorm", FrameAnimation_DESC("Maelstorm", 0.1f));
	//	AuraRenderer2->ChangeFrameAnimation("Maelstorm");
	//	AuraRenderer2->GetTransform().SetLocalScale({ 64.f,64.f,1.f });
	//	AuraRenderer2->GetColorData().MulColor.a = 0.6f;
	//	//float4 RenderWorldPos = AuraRenderer2->GetTransform().GetWorldPosition();
	//	AuraRenderer2->GetTransform().SetLocalPosition({ 0.f,0.f,-4.f });
	//	//AuraRenderer2->GetTransform().SetWorldPosition(RenderWorldPos);


	//}




	{
		BiconRenderer = CreateComponent<GameEngineTextureRenderer>();
		BiconRenderer->CreateFrameAnimationFolder("pool", FrameAnimation_DESC("pool", 0.1f));
		BiconRenderer->ChangeFrameAnimation("pool");
		BiconRenderer->GetTransform().SetLocalScale({ 96.f,128.f,1.f });
		float4 RenderWorldPos = BiconRenderer->GetTransform().GetWorldPosition();
		BiconRenderer->GetTransform().SetWorldPosition({ RenderWorldPos.x - 5.f, RenderWorldPos.y - 5.f , 1.f });


	}


	{
		BackRenderer = CreateComponent<GameEngineTextureRenderer>();
		BackRenderer->CreateFrameAnimationFolder("Archonback0", FrameAnimation_DESC("Archonback0", 0.1f));
	//	float4 RenderWorldPos = BackRenderer->GetTransform().GetWorldPosition();
		//BackRenderer->GetTransform().SetWorldPosition({ RenderWorldPos.x, RenderWorldPos.y , 100.f });
		BackRenderer->GetTransform().SetLocalPosition({ 0.f,0.f,-1.f });
		BackRenderer->ChangeFrameAnimation("Archonback0");
		BackRenderer->GetTransform().SetLocalScale({ 120.f,120.f,1.f });
	}


	


}

void Arcon::Update(float _DeltaTime)
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
				TestUni = GetLevel()->CreateActor<ArconBul>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(TarGetPos);
				TestUni->TarGet = TarGet;

			}


			break;
		}


		if (MonCount == Monsize)
		{
			AttCheck = false;
			BAniChange = false;
			Renderer->ChangeFrameAnimation("ArchonMove12");
			AttTime = 0.f;
		}


	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });




}

void Arcon::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("ArchonAttack0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("ArchonAttack1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("ArchonAttack2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("ArchonAttack3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("ArchonAttack4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("ArchonAttack5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("ArchonAttack6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("ArchonAttack7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("ArchonAttack8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("ArchonAttack9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("ArchonAttack10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("ArchonAttack11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("ArchonAttack12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("ArchonAttack13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("ArchonAttack14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("ArchonAttack15");
	}


}
