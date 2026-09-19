class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(xCenter+radius>=x1 && xCenter+radius<=x2) {
            if(yCenter+radius>=y1 && yCenter+radius<=y2) {
                return true;
            }
            
        }
        if(xCenter-radius>=x1 && xCenter-radius<=x2) {
            if(yCenter-radius>=y1 && yCenter-radius<=y2) {
                return true;
            }
            
        }
        if(x1>=xCenter-radius && x1<=xCenter+radius) {
            if(y1>=yCenter-radius && y1<=yCenter+radius) {
                return true;
            }
        }
        if(x2>=xCenter-radius && x2<=xCenter+radius) {
            if(y2>=yCenter-radius && y2<=yCenter+radius) {
                return true;
            }
        }
        if(x1>=xCenter-radius && x1<=xCenter+radius) {
            if(yCenter+radius>=y1 && yCenter+radius<=y2) {
                return true;
            }
        }
        if(xCenter>x1 && xCenter<x2) {
            if(yCenter>y1-radius && yCenter<y2) {
                return true;
            }
        }
        if(y2-radius==yCenter) return true;
        
        else return false;
    }
};