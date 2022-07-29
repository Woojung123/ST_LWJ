
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class Storm : public UnitBase
{
public:
	// constrcuter destructer
	Storm();
	~Storm();

	// delete Function
	Storm(const Storm& _Other) = delete;
	Storm(Storm&& _Other) noexcept = delete;
	Storm& operator=(const Storm& _Other) = delete;
	Storm& operator=(Storm&& _Other) noexcept = delete;

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

