///< @author Roma, Timofey, Yaroslav

class King:public BaseFigure{   ///< ����� ������
public:
    King(int type0, int x_cell0, int y_cell0, COLORREF main_color0, COLORREF side_color0) : BaseFigure(type0, x_cell0, y_cell0, main_color0, side_color0){} ///< �����������
    virtual void draw(int type0, int x_cell0, int y_cell0) override;                    ///< ���������
    virtual void count_move_ability_cells(vector<BaseFigure*> figures) override;        ///< ������� ����������� �����
    virtual void change() override{}
};

void King::draw(int x, int y, int r){
    txSetColor(side_color,2);
    txSetFillColor (RGB (255, 215, 0)); ///< ������ ��� ������

    POINT headtop[25] = {{(6*r)+x, (0*r)+y}, {(7*r)+x, (6*r)+y}, {(8*r)+x, (0*r)+y},
                     {(9*r)+x, (6*r)+y}, {(10*r)+x, (0*r)+y}, {(11*r)+x, (6*r)+y},
                     {(12*r)+x, (0*r)+y}, {(13*r)+x, (6*r)+y}, {(14*r)+x, (0*r)+y},
                     {(15*r)+x, (6*r)+y}, {(16*r)+x, (0*r)+y}, {(16*r)+x, (8*r)+y},
                     {(14*r)+x, (8*r)+y}, {(12*r)+x, (18*r)+y}, {(13*r)+x, (18*r)+y},
                     {(13*r)+x, (19*r)+y}, {(14*r)+x, (19*r)+y}, {(14*r)+x, (20*r)+y},
                     {(8*r)+x, (20*r)+y}, {(8*r)+x, (19*r)+y}, {(9*r)+x, (19*r)+y},
                     {(9*r)+x, (18*r)+y}, {(10*r)+x, (18*r)+y}, {(8*r)+x, (8*r)+y}, {(6*r)+x, (8*r)+y}}; //"������", �������� � ����������� �� ������
    txPolygon (headtop, 25);

    /*POINT headnottop[26] = {{(2*r)+x, (0*r)+y}, {(3*r)+x, (4*r)+y}, {(3*r)+x, (0*r)+y},
                           {(4*r)+x, (4*r)+y}, {(4*r)+x, (0*r)+y}, {(5*r)+x, (4*r)+y},
                           {(6*r)+x, (4*r)+y}, {(7*r)+x, (0*r)+y}, {(7*r)+x, (4*r)+y},
                           {(8*r)+x, (0*r)+y}, {(8*r)+x, (4*r)+y}, {(9*r)+x, (0*r)+y},
                           {(9*r)+x, (5*r)+y}, {(7*r)+x, (5*r)+y}, {(6*r)+x, (9*r)+y},
                           {(7*r)+x, (9*r)+y}, {(7*r)+x, (10*r)+y}, {(8*r)+x, (10*r)+y},
                           {(8*r)+x, (11*r)+y}, {(3*r)+x, (11*r)+y}, {(3*r)+x, (10*r)+y},
                           {(4*r)+x, (10*r)+y}, {(4*r)+x, (9*r)+y}, {(5*r)+x, (9*r)+y},
                           {(4*r)+x, (5*r)+y}, {(2*r)+x, (5*r)+y}}; //"������", �������� � ����������� �� ������
    txPolygon (headnottop, 26);*/

    txSetFillColor (main_color); ///< �������� ���� (�����)
    //txSetFillColor (RGB (255, 255, 255)); ///< �������� ���� (������)

    POINT body[4] = {{(10*r)+x, (20*r)+y}, {(12*r)+x, (20*r)+y}, {(16*r)+x, (40*r)+y}, {(6*r)+x, (40*r)+y}}; ///< ������������ ����
    txPolygon (body, 4);

    POINT stand1[4] = {{(4*r)+x, (40*r)+y}, {(18*r)+x, (40*r)+y}, {(18*r)+x, (42*r)+y}, {(4*r)+x, (42*r)+y}}; ///< ������ ��������� ��� ����, � � ����� ������ ���
    txPolygon (stand1, 4);

    POINT stand2[4] = {{(2*r)+x, (42*r)+y}, {(20*r)+x, (42*r)+y}, {(20*r)+x, (44*r)+y}, {(2*r)+x, (44*r)+y}}; ///< ������ ��������� ��� �������(�����,����,����) � ������
    txPolygon (stand2, 4);

    POINT stand3[4] = {{(0*r)+x, (44*r)+y}, {(22*r)+x, (44*r)+y}, {(22*r)+x, (46*r)+y}, {(0*r)+x, (46*r)+y}};///< ������ ��������� ��� ������(������, �������)
    txPolygon (stand3, 4);
}

void King :: count_move_ability_cells(vector<BaseFigure*> figures) {
    move_ability_cells.clear();
    if((x_cell+1) < 8 && (y_cell-1) >= 0)
    {                                           ///< ����� �����
        int* cell = new int[2];
        cell[0] = y_cell - 1;
        cell[1] = x_cell + 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell - 1)) && (figura->get_x_cell() == (x_cell + 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                  // out = true;
                   break;
            }
        }
    }
    if((x_cell -1) >= 0 && (y_cell-1) >= 0)
    {                                           ///< ����� �����
        int* cell = new int[2];
        cell[0] = y_cell - 1;
        cell[1] = x_cell - 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell - 1)) && (figura->get_x_cell() == (x_cell - 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                 //  out = true;
                   break;
            }
        }
    }
    if((x_cell+1) < 8 && (y_cell+1) < 8)
    {                                           ///< ���� ������
        int* cell = new int[2];
        cell[0] = y_cell + 1;
        cell[1] = x_cell + 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell + 1)) && (figura->get_x_cell() == (x_cell + 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                 //  out = true;
                   break;
            }
        }
    }
    if((x_cell-1) >= 0 && (y_cell+1) < 8)
    {                                           ///< ���� �����
        int* cell = new int[2];
        cell[0] = y_cell + 1;
        cell[1] = x_cell - 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell + 1)) && (figura->get_x_cell() == (x_cell - 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                  // out = true;
                   break;
            }
        }
    }
    if((y_cell-1) >= 0)
    {                                           ///< �����
        int* cell = new int[2];
        cell[0] = y_cell - 1;
        cell[1] = x_cell;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell - 1)) && (figura->get_x_cell() == (x_cell))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   //out = true;
                   break;
            }
        }
    }
    if((y_cell+1) < 8)
    {                                           ///< ����
        int* cell = new int[2];
        cell[0] = y_cell + 1;
        cell[1] = x_cell;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell + 1)) && (figura->get_x_cell() == (x_cell))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   //out = true;
                   break;
            }
        }
    }
    if((x_cell+1) < 8)
    {                                           ///< ������
        int* cell = new int[2];
        cell[0] = y_cell;
        cell[1] = x_cell + 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell)) && (figura->get_x_cell() == (x_cell + 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   //out = true;
                   break;
            }
        }
    }
    if((x_cell-1) >= 0)
    {                                           ///< �����
        int* cell = new int[2];
        cell[0] = y_cell;
        cell[1] = x_cell - 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell)) && (figura->get_x_cell() == (x_cell - 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   //out = true;
                   break;
            }
        }
    }
}
