class Solution {
    public int reverse(int x) {
        long reversedNumber = 0;
        
        while (x != 0) {
            reversedNumber = reversedNumber * 10 + x % 10;
            x /= 10;
        }
        
        // Verifica si el número invertido está dentro del rango de int
        if (reversedNumber > Integer.MAX_VALUE || reversedNumber < Integer.MIN_VALUE) {
            return 0;
        }
        
        return (int) reversedNumber;
    }
}