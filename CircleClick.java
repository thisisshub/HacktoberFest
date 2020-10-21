import java.applet.Applet;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.*;
public class CircleClick extends Applet implements MouseListener{
	public void paint(Graphics g) {
		addMouseListener(this);
		
	}
	public Color giveColor() {
		Color c;
		Color[] color = {Color.black,Color.blue,Color.cyan,Color.DARK_GRAY,Color.green,Color.MAGENTA,Color.ORANGE,Color.RED,Color.YELLOW};
		Random r = new Random();
		int i = r.nextInt(color.length);
		c = color[i];
		return c;
	}
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		Graphics g = getGraphics();
		Color c = giveColor();
		g.setColor(c);
		g.fillOval(e.getXOnScreen(),e.getYOnScreen(),100,100);
		
		
	}
	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		repaint();
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		
		
	}
	
}
