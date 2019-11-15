#include "JobStream.h"
#include "queue.h"

JobStream::JobStream(unsigned int val)
{
	if ((val < 1) || (val > MaxSize)) throw (val);
	tact_need = val;
}
