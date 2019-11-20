#pragma once
class JobStream
{
private:
	unsigned int tact_need;
public:
	JobStream(unsigned int val);
	int get_need() { return tact_need; };
};
