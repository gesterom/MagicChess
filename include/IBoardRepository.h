
class IBoardRepository
{
	virtual bool Commit(From,To);
	virtual Pawn GetPawn(From);
	virtual ~IBoardRepository(){}
};
