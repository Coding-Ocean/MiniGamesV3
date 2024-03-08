#pragma once
namespace GAME03 
{
	class FADE
	{
	public:
		FADE();
		~FADE();
		void setTime(float time);
		void inStart();
		bool inEndFlag();
		void outStart();
		bool outEndFlag();
		void proc();
	private:
		enum STATE {
			IN_START, IN_END,
			OUT_START, OUT_END
		};
		STATE State;
		float Red, Green, Blue;
		float Alpha;
		float Speed;
	};
}

