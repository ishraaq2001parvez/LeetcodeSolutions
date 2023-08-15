/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
import java.util.*;
class Solution {
    public static Vector<Integer> getSmaller(ListNode head, int x){
        Vector<Integer> v=new Vector<Integer>();
        while(head!=null){
            if(head.val<x){
                v.add(head.val);
            }
            head=head.next;
        }
        return v;
    }
    public static Vector<Integer> getLarger(ListNode head, int x){
        Vector<Integer> v=new Vector<Integer>();
        while(head!=null){
            if(head.val>=x){
                v.add(head.val);
            }
            head=head.next;
        }
        return v;
    }
    public static void modify(ListNode head, Vector<Integer> v1, Vector<Integer> v2){
        for(int i=0;i<v1.size();i++){
            head.val=v1.get(i); 
            head=head.next;
        }
        for(int i=0;i<v2.size();i++){
            head.val=v2.get(i); 
            head=head.next;
        }
    }
    public ListNode partition(ListNode head, int x) {
        Vector<Integer> v1= getSmaller(head, x); 
        Vector<Integer> v2=  getLarger(head, x); 
        modify(head, v1, v2);
        return head;
        
    }
}