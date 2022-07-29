

#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class TestUI : public GameEngineActor
{
public:
	// constrcuter destructer
	TestUI();
	~TestUI();

	// delete Function
	TestUI(const TestUI& _Other) = delete;
	TestUI(TestUI&& _Other) noexcept = delete;
	TestUI& operator=(const TestUI& _Other) = delete;
	TestUI& operator=(TestUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

