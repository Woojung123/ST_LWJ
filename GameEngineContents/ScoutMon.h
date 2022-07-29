

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include"StageMain.h"
#include "GlobalContentsValue.h"
#include "UnitBase.h"
// Ό³Έν :
class ProDeath;
class GameEngineTextureRenderer;
class ScoutMon : public UnitBase
{
public:
	// constrcuter destructer
	ScoutMon();
	~ScoutMon();

	// delete Function
	ScoutMon(const ScoutMon& _Other) = delete;
	ScoutMon(ScoutMon&& _Other) noexcept = delete;
	ScoutMon& operator=(const ScoutMon& _Other) = delete;
	ScoutMon& operator=(ScoutMon&& _Other) noexcept = delete;

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

