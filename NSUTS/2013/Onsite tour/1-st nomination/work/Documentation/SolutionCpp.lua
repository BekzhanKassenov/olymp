function sqr(x)
    return x*x
end
function Distance(x1, y1, x2, y2)
    return math.sqrt(sqr(x1-x2) + sqr(y1-y2))
end

pathIndex = nil

--�������� � ���������� �����
function ShootAtClosest()
    local mX, mY = api:position(0) --���� ����������
    local n = api:count() --���������� ������ � ������� ���������
    local myOwner = api:owner(0)--��� ����� ������ (�������� ������)

    local closestEnemy = 1.5*api.field_size
    local shotX = nil
    local shotY = nil
    for i = 1, n do
        if (api:type(i) == 2) then -- ���� - �����
            local town = api:owner(i); -- ���� ����������� �����
            if (town ~= myOwner and town >= 0) then -- ���� ��������� �����
                local sx, sy = api:position(i) -- ������� ���������� ������
                local dist = Distance(sx, sy, mX, mY) -- ���������� �� ����
                if (dist < closestEnemy) then -- �������� �� ���������� ����������
                    shotX, shotY = sx, sy -- ���������� ����������, ���� ����� ��������� ����� ��� ���������� ���������
                    closestEnemy = dist;
                end
            end
        end
    end
    if (shotX) then -- ���� ����� ���� ������ � ������� ���������
        api:shoot_at_pos(shotX, shotY)
    else
        api:shoot_stop()
    end
end

function MoveToPoint(x, y) -- ��������� � ����� x,y
    local mX, mY = api:position(0)
    api:move_by_delta(x-mX, y-mY)
end

function MoveAlongPath(path, isCycle) -- ��������� ����� ������� path, ���� isCycle = true, �� ������������� �� �������
    if (path == nil) then
        return
    end
    if (pathIndex == nil) then
        pathIndex = 0
    end
        local mX, mY = api:position(0)
        if (Distance(mX, mY, path[pathIndex].x, path[pathIndex].y) < 1e-5) then
          pathIndex = pathIndex + 1
        end
    if (path[pathIndex] == nil) then
        if (not isCycle) then
            return
        end
        pathIndex = 0
    end
    MoveToPoint(path[pathIndex].x, path[pathIndex].y)
end


function Think()
    if (path) then -- ��������� � ����������� �� ���� ������, ������������� � ������� Program (ProgramRobot ��� fpc). ���� ����� ���������� �� �������, ���� ����� ���������� � ������������ �������
        MoveAlongPath(path, true);
    else
        MoveToPoint(gofact.x, gofact.y);
    end
    ShootAtClosest() -- �������� � ���������� ���������
end
