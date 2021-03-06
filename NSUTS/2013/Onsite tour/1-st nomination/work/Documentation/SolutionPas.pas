Unit Solution;

interface 
procedure ProgramRobot(index : longint; var data : pchar; var dataLen : longint; var prog : pchar; var progLen : longint);
procedure Strategy();

implementation
    uses DataTypes, strings;

    procedure ProgramRobot(index : longint; var data : pchar; var dataLen : longint; var prog : pchar; var progLen : longint);
    var S : string;
         buff : string;
          num : longint;
    begin
      if ((index mod 2) = 1) then
      begin
	    //����� � ������ ���������������� ������ �� LUA (����� ���� ��� �������)
        prog := 'path = {} path[0] = {x = 1, y = 1} path[1] = {x = 999, y = 1} path[2] = {x = 999, y = 999} path[3] = {x = 1, y = 999}';
        progLen := strlen(prog);
      end
      else
      begin
        //�������� ������������ �����
        num := Index mod 7;
        //����� ���������������� ������: ������ � ����� ����� ������
        s := 'gofact = {x = ';
        str(world^.factories[num].position.x, buff);
        s := s+buff+ ', y = ';
        str(world^.factories[num].position.y, buff);
        s := s+buff+'}'; 
        //�������� ��������� �� ������
        prog := pchar(ansistring(s));
        //� ����� ������
        progLen := strlen(prog);
      end
    end;

    procedure Strategy();
    var
        i : longint;
    begin
        for i := 0 to MAX_FACTORY_COUNT - 1 do
        begin
            if ((world^.factories[i].id    <> -1) and //���������� "������" ������
                (world^.factories[i].owner = playerIndex)) then
            begin
            	//���� ����� ���, �� ������� ������� �� ��� �������
                SetBuildAt(i, 0);
            end;
        end;
    end;
end.
