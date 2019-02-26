class FildPosition;
class FildPositions;
class IPawn_view;
class PawnID;
class IPawn;
class CommitStatus;

template<typename T>
class Reference;

class IBoardRepository{
	public:
		virtual CommitStatus commitMove(FildPosition from,FildPosition to) = 0; //sucess
		virtual Reference<IPawn> getPawn(FildPosition from) = 0; // ? 
		virtual FildPositions allFildPosition() = 0;
		virtual ~IBoardRepository(){}
};

class IPawnRepository{
	public:
		virtual FildPositions posibleMoveForPawn(PawnID pawnID) = 0;
		virtual Reference<IPawn> createPawn(PawnID pawnID) = 0; 
		virtual ~IPawnRepository(){}
};
