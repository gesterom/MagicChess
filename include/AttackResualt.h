#pragma once

class AttackResualt
{
	bool killed;
	public:
	AttackResualt( bool aa ) {
		this->killed = aa;	
	}
	bool isKilled(){return killed;}
};
