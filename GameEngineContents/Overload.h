
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include"StageMain.h"
#include "GlobalContentsValue.h"
#include "UnitBase.h"
// Ό³Έν :
class ZergDeath;
class GameEngineTextureRenderer;
class Overload : public UnitBase
{
public:
	// constrcuter destructer
	Overload();
	~Overload();

	// delete Function
	Overload(const Overload& _Other) = delete;
	Overload(Overload&& _Other) noexcept = delete;
	Overload& operator=(const Overload& _Other) = delete;
	Overload& operator=(Overload&& _Other) noexcept = delete;

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

