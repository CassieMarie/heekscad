// EndedObject.h
// Copyright (c) 2009, Dan Heeks
// This program is released under the BSD license. See the file COPYING for details.

#pragma once

#include "../interface/HeeksObj.h"
#include "../interface/HeeksColor.h"
#include "ConstrainedObject.h"

class EndedObject: public ConstrainedObject{
public:
	gp_Pnt A, B;
	double ax,ay,bx,by;

	~EndedObject(void);
	EndedObject();

	const EndedObject& operator=(const EndedObject &b);

	virtual void LoadToDoubles();
	virtual void LoadFromDoubles();

	// HeeksObj's virtual functions
	bool Stretch(const double *p, const double* shift, void* data);
	bool ModifyByMatrix(const double* m);
	bool GetStartPoint(double* pos);
	bool GetEndPoint(double* pos);
	void CopyFrom(const HeeksObj* object){operator=(*((EndedObject*)object));}
	void GetGripperPositions(std::list<GripData> *list, bool just_for_endof);
};