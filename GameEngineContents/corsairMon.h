
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include"StageMain.h"
#include "GlobalContentsValue.h"
#include "UnitBase.h"
// Ό³Έν :
class ProDeath;
class GameEngineTextureRenderer;
class corsairMon : public UnitBase//, public GameEngineActor
	
{
public:
	// constrcuter destructer
	corsairMon();
	~corsairMon();

	// delete Function
	corsairMon(const corsairMon& _Other) = delete;
	corsairMon(corsairMon&& _Other) noexcept = delete;
	corsairMon& operator=(const corsairMon& _Other) = delete;
	corsairMon& operator=(corsairMon&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;
	ProDeath* DeathEff;
	float4 Color;
	float4	m_Dir;
	std::vector<MapPoint> CheckPoint;
public:
	void SetCheckPoinr(MapPoint _MapP)
	{
		CheckPoint.push_back(_MapP);
	}

	

private:
	void Move(float _DeltaTime);
	void ChangeAni(float4 _Gopoint, float4 _WorldPos);
	float Speed;
};

