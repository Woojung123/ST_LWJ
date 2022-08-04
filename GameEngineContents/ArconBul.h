
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class ArconBul : public UnitBase
{
public:
	// constrcuter destructer
	ArconBul();
	~ArconBul();

	// delete Function
	ArconBul(const ArconBul& _Other) = delete;
	ArconBul(ArconBul&& _Other) noexcept = delete;
	ArconBul& operator=(const ArconBul& _Other) = delete;
	ArconBul& operator=(ArconBul&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;
	void AttEnd(const FrameAnimation_DESC& _Info);
	bool	BAniChange;
	float4 Color;

private:
	float Speed;
	float4 m_Dir;

	float m_dotDam;

public:
	GameEngineActor* TarGet;
	void SetTarGet(GameEngineActor* _TarGet)
	{
		TarGet = _TarGet;
	}
};

