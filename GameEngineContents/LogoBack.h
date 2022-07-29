
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class LogoBack : public GameEngineActor
{
public:
	// constrcuter destructer
	LogoBack();
	~LogoBack();

	// delete Function
	LogoBack(const LogoBack& _Other) = delete;
	LogoBack(LogoBack&& _Other) noexcept = delete;
	LogoBack& operator=(const LogoBack& _Other) = delete;
	LogoBack& operator=(LogoBack&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
	bool Deathcheck;
	float TimeAngle;
};

