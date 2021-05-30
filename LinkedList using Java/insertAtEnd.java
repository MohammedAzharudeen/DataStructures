package DataStructures;

public class Node {
	int data;
	Node next;
}

                  ------------------------------------------------------------------------------------------------------------------------------------------
                    
public class Runner {

	public static void main(String[] args) {
		LinkedList list = new LinkedList();
		list.insert(18);
		list.insert(45);
		list.insert(12);
		
		list.show();
	}

}

                  ------------------------------------------------------------------------------------------------------------------------------------------

public class LinkedList 
{
	Node head;
	
	public void insert(int data)                        //to insert at end.
	{
		Node node = new Node();
		node.data = data;
		node.next = null;
		
		if(head == null)                                   //if the list is empty.
		{
			head = node;
		}
		else
		{
			Node n = head;
			while(n.next != null)
			{
				n = n.next;
			}
			n.next = node;
		}
	}
	
	public void show()                                    //to print the list.
	{
		Node node = head;
		while(node.next != null)
		{
			System.out.println(node.data);
			node = node.next;
		}
		System.out.println(node.data);
	}
}
