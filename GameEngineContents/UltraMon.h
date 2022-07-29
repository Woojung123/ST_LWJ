
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include"StageMain.h"
#include "GlobalContentsValue.h"
#include "UnitBase.h"
// Ό³Έν :
class ZergDeath;
class GameEngineTextureRenderer;
class UltraMon : public UnitBase
{
public:
	// constrcuter destructer
	UltraMon();
	~UltraMon();

	// delete Function
	UltraMon(const UltraMon& _Other) = delete;
	UltraMon(UltraMon&& _Other) noexcept = delete;
	UltraMon& operator=(const UltraMon& _Other) = delete;
	UltraMon& operator=(UltraMon&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;
	ZergDeath* DeathEff;
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

