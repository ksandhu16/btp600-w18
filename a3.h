class Builder{

public: 
	//add a pure virtual function for building chairs
	//add a pure virtual function for building tables
	//add a pure virtual function for building computers
};

class Director{
	//add what data members you think you need here

public:
	void setBuilder(Builder& b){
		//...
	}

	Room* buildRoom(int numStudents){
		Room* rc=new Room();
		//...
		return rc;
	}

};
class ALCBuilder{
public:

};
class LabBuilder{
public:

};
class StepRoomBuilder{
public:
};
