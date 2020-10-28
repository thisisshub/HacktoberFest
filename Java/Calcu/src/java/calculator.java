import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author nithesh
 */

@WebServlet(urlPatterns = {"/calculator"})
public class calculator extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        PrintWriter out = response.getWriter();
                String n1 = request.getParameter("txt1");
                String n2 = request.getParameter("txt2");
                String op = request.getParameter("op");          
                out.println("<html>\n" +"<head>\n" +"<title>Result</title>\n" +"<link href =\"style.css\" rel=\"stylesheet\">\n" +
                "<link href=\"https://fonts.googleapis.com/css2?family=Poppins:wght@500&display=swap\" rel=\"stylesheet\">\n" +
                "</head>\n" +"<body>\n" +"<div class=\"widget center\">\n" +"<div class=\"blur\"></div>\n" +"<div class=\"text center\" align=\"center\">\n" +
                "<br>\n" +"<br>\n");
        switch (op) {
            case "Addition":
                out.println("Answer = "+(Integer.parseInt(n1) + Integer.parseInt(n2)));
                break;
            case "Subtraction":
                out.println("Answer = "+(Integer.parseInt(n1) - Integer.parseInt(n2)));
                break;
            case "Multiplication":
                out.println("Answer = "+(Integer.parseInt(n1) * Integer.parseInt(n2)));
                break;
            default:
                out.println("Answer = "+(Integer.parseInt(n1) / Integer.parseInt(n2)));
                break;
        } 
        out.println("</div></div></body></html>");
        
    }
}