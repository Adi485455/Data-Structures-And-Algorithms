class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        /* Main point here is to identify the pattern or should we say the rectangles are overlappin
        // The one point here we need to notice that to rectangle to overalp we must need one side less than other side (one edge inside another edge)
        So we need is the codition like the leftmost rightest boundary of the rectangle is must smaller than rightmost leftest boundary yehh thats the pattern
        considering these are our rectangles rect 1 = [x1, y1, x2, y2] and rect 2 = [x3, y3, x4, y4]
        So condition is the :-
        leftmost rightest boundary :- max(x1,x3)
        rightmost leftest boundary :- min (x2,x4)
        max(x1,x3) < min(x2,x4)
        and similar condition for the y also
        and we need both the condition to be true at same time 
        */
        int x1=rec1[0];
        int x2=rec1[2];
        int y1=rec1[1];
        int y2=rec1[3];
        int x3=rec2[0];
        int x4=rec2[2];
        int y3=rec2[1];
        int y4=rec2[3];
        
        bool x_cond = max(x1,x3) < min(x2,x4);
        bool y_cond = max(y1,y3) < min(y2,y4);

        if(x_cond && y_cond){
            return true ;
        }else{
            return false;
        }
    }
};