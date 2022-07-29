
#pragma once
#include <GameEngineCore/GameEngineLevel.h>


struct MapPoint
{
	float4 TurnPoint;
	bool	TurnCheck = true;

};


// Ό³Έν :
class StageMain : public GameEngineLevel
{
public:

	
	// constrcuter destructer
	StageMain();
	~StageMain();

	// delete Function
	StageMain(const StageMain& _Other) = delete;
	StageMain(StageMain&& _Other) noexcept = delete;
	StageMain& operator=(const StageMain& _Other) = delete;
	StageMain& operator=(StageMain&& _Other) noexcept = delete;

	
	std::vector<MapPoint> CheckPoint;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
	bool StartCheck;
	float StartTime;
	float GamePlayTime;


	int MonCount;
	int MonMax;

	float MonTimeMax;
	float MonTime;


	int StageCount;



private:
	void Stage1(float _DeltaTime) ;
	void Stage2(float _DeltaTime) ;
	void Stage3(float _DeltaTime) ;
	void Stage4(float _DeltaTime) ;
	void Stage5(float _DeltaTime) ;
	void Stage6(float _DeltaTime) ;
	void Stage7(float _DeltaTime) ;
	void Stage8(float _DeltaTime) ;
	void Stage9(float _DeltaTime) ;
	void Stage10(float _DeltaTime);
	void Stage12(float _DeltaTime);
	void Stage13(float _DeltaTime);
	void Stage14(float _DeltaTime);
	void Stage15(float _DeltaTime);
	void Stage16(float _DeltaTime);
	void Stage17(float _DeltaTime);
	void Stage18(float _DeltaTime);
	void Stage19(float _DeltaTime);
	void Stage20(float _DeltaTime);
	void Stage21(float _DeltaTime);
	void Stage22(float _DeltaTime);
	void Stage23(float _DeltaTime);
	void Stage24(float _DeltaTime);
	void Stage25(float _DeltaTime);


};

