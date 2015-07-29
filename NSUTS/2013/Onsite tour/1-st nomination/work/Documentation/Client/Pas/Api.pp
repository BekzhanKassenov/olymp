library Api;
{$mode objfpc}{$H+}
{$ASSERTIONS+}

uses DataTypes, Solution;

procedure InitWorld (ptr : ptrWorldData; playerIdx : longint) ; stdcall;
begin
    world := ptr;
    playerIndex := playerIdx;
end;

procedure SolutionProgram(index : longint; Out data : pchar; Out dataLen : longint; Out prog : pchar; Out progLen : longint) ; stdcall;
begin
    ProgramRobot(index, data, dataLen, prog, progLen);
end;

procedure SolutionStrategy(robotTypes : plongint) ; stdcall;
begin
    robotTypesArray := robotTypes;
    Strategy();
end;



procedure TestWorld (world : ptrWorldData; playerIdx : longint) ; stdcall;
const 
	eps = 1e-10;
begin
	Assert(world^.maximalMatchTime = 1234567);
	Assert(abs(world^.factoryClasses[0].radius - 1.1) < eps);
	Assert(world^.factoryClasses[0].score = 1000000009);

	Assert(abs(world^.robotClasses[0].maxSpeed - 100.555) < eps);
	Assert(world^.robotClasses[0].timeToBuild = 17239);

	Assert(world^.projectileClasses[0].isHoming = 10);
	Assert(abs(world^.projectileClasses[0].speed - 777.777) < eps);

	Assert(world^.factories[5].id = 7);
	Assert(abs(world^.factories[5].position.x - 0.5) < eps);
	Assert(abs(world^.factories[5].position.y - 123123) < eps);
	Assert(world^.factories[5].captureProgressTime = 81);

	Assert(world^.robots[100].id = 111112222);
	Assert(abs(world^.robots[100].position.x - 111111.5) < eps);
	Assert(abs(world^.robots[100].position.y - 17171) < eps);
	Assert(world^.robots[100].shootTimeRemaining = 1919);

	Assert(world^.projectiles[7].id = 111);
	Assert(abs(world^.projectiles[7].position.x - 87777) < eps);
	Assert(abs(world^.projectiles[7].position.y - 123.55) < eps);
	Assert(world^.projectiles[7].homingTargetId = 1160);
end;



exports InitWorld;
exports SolutionProgram;
exports SolutionStrategy;
exports TestWorld;

end.
