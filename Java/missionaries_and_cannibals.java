import java.util.ArrayList;
import java.util.HashMap;


class Node{
	public int noOfMisStart;
	public int noOfCanStart;
	public int noOfMisDest;
	public int noOfCanDest;
	public int fValue;
	
	public Node() {
		
	}
	
	public Node(Node node) {
		this.noOfMisStart = node.noOfMisStart;
		this.noOfCanStart = node.noOfCanStart;
		this.noOfMisDest = node.noOfMisDest;
		this.noOfCanDest = node.noOfCanDest;
		this.fValue = node.fValue;
	}
	
	public Node(int noOfMisStart, int noOfCanStart, int noOfMisDest, int noOfCanDest, int fValue) {
		this.noOfMisStart = noOfMisStart;
		this.noOfCanStart = noOfCanStart;
		this.noOfMisDest = noOfMisDest;
		this.noOfCanDest = noOfCanDest;
		this.fValue = fValue;
	}
}

public class MissionariesAndCannibals {
	int hValue = 1;
	Node finalState = new Node(0, 0, 3, 3, 0);
	Node currentState = new Node(3, 3, 0, 0, 0);	
	ArrayList<String> action = new ArrayList<String>();

	private int checkFValue(Node stepNodes) {
		// f[x] = g[x] + h[x]
		return ((6 - (stepNodes.noOfCanDest + stepNodes.noOfMisDest)) + hValue);
	}
	
	private boolean isLegalMove(Node node) {
		if (node.noOfMisDest < node.noOfCanDest && node.noOfMisDest != 0) {
			return false;
		}
		
		if (node.noOfMisStart < node.noOfCanStart && node.noOfMisStart != 0){
			return false;
		}
		
		if (node.noOfMisStart < 0 || node.noOfMisDest < 0){
			return false;
		}
		
		if (node.noOfCanDest < 0 || node.noOfCanStart < 0){
			return false;
		}
		
		if (node.noOfMisStart > 3 || node.noOfMisDest > 3){
			return false;
		}
		
		if (node.noOfCanDest > 3 || node.noOfCanStart > 3){
			return false;
		}
		
		return true;
	}
	
	public static void main(String[] args) {
		MissionariesAndCannibals obj = new MissionariesAndCannibals();
		obj.logic();
	}

	private void logic() {
		String movingTo = "destination";
		Node node2 = new Node();
		
		action.add("01");
		action.add("10");
		action.add("11");
		action.add("20");
		action.add("02");
		
		ArrayList<Node> listNodes = new ArrayList<>();
		HashMap<String, Integer> actionCount = new HashMap<String, Integer>();

		actionCount.put("10", 0);
		actionCount.put("01", 0);
		actionCount.put("11", 0);
		actionCount.put("20", 0);
		actionCount.put("02", 0);
		
		System.out.println(currentState.noOfMisStart + " + " + currentState.noOfCanStart + "\t\t\t --Start-To-Destination--> \t\t\t" + currentState.noOfMisDest + " + " + currentState.noOfCanDest + "\n\n");
		
		while (!(currentState.noOfCanDest == 3 && currentState.noOfMisDest == 3)) {
			node2.fValue = 999;
			hValue += 1;
			
			if (movingTo.equals("destination")) {
				for (String task: action) {
					if (actionCount.get(task) > 4 && actionCount.get(task) > 0) {
						actionCount.put(task, -3);
						continue;
					}
					
					if (actionCount.get(task) < 0) {
						actionCount.put(task, actionCount.get(task) + 1);
						continue;
					}
					
					Node tempNode = new Node(currentState);
					// 0 1
					tempNode.noOfMisStart = tempNode.noOfMisStart - Integer.parseInt(task.charAt(0) + "");
					tempNode.noOfMisDest = tempNode.noOfMisDest + Integer.parseInt(task.charAt(0) + "");
					tempNode.noOfCanStart = tempNode.noOfCanStart - Integer.parseInt(task.charAt(1) + "");
					tempNode.noOfCanDest = tempNode.noOfCanDest + Integer.parseInt(task.charAt(1) + "");
					tempNode.fValue = checkFValue(tempNode);

					if (tempNode.fValue < node2.fValue) {
						if (isLegalMove(tempNode)) {
							node2 = new Node(tempNode);
							listNodes.add(new Node(tempNode));
							movingTo = "start";
							int count1 = actionCount.get(task);
							actionCount.put(task, ++count1);
						}
					}
				}

				listNodes.remove(node2);
				currentState = new Node(listNodes.get(listNodes.size() - 1));
				listNodes.remove(currentState);
				System.out.println(currentState.noOfMisStart + " + " + currentState.noOfCanStart + "\t\t\t --Start-To-Destination--> \t\t\t" + currentState.noOfMisDest + " + " + currentState.noOfCanDest);
			}
			
			else if (movingTo.equalsIgnoreCase("start")) {
				for (String task: action) {
					if (actionCount.get(task) > 4) {
						actionCount.put(task, 0);
						continue;
					}
					
					Node tempNode = new Node(currentState);
					
					tempNode.noOfMisStart = tempNode.noOfMisStart + Integer.parseInt(task.charAt(0) + "");
					tempNode.noOfMisDest = tempNode.noOfMisDest - Integer.parseInt(task.charAt(0) + "");
					tempNode.noOfCanStart = tempNode.noOfCanStart + Integer.parseInt(task.charAt(1) + "");
					tempNode.noOfCanDest = tempNode.noOfCanDest - Integer.parseInt(task.charAt(1) + "");
					tempNode.fValue = checkFValue(tempNode);
					
					if (tempNode.fValue < node2.fValue) {
						if (isLegalMove(tempNode)) {
							node2 = new Node(tempNode);
							listNodes.add(new Node(tempNode));
							movingTo = "destination";	
							int count1 = actionCount.get(task);
							actionCount.put(task, ++count1);
						}
					}
				}
				
				listNodes.remove(node2);
				currentState = new Node(listNodes.get(listNodes.size() - 1));
				listNodes.remove(currentState);
				System.out.println(currentState.noOfMisStart + " + " + currentState.noOfCanStart + " \t\t\t <--Destination-To-Start-- \t\t\t" + currentState.noOfMisDest + " + " + currentState.noOfCanDest + "\n\n");
			}
		}
	}
}
