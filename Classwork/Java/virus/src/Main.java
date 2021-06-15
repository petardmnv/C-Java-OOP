public class Main {
    public static void main(String[] args) {
        while(true)
        {
            new Thread(() -> {
                System.out.println(Thread.currentThread().getName());
                while(true){
                    new Thread(() -> {
                        System.out.println(Thread.currentThread().getName());
                        try {
                            main(new String[]{});
                            Thread.sleep(2200);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    });
                    try {
                        Thread.sleep(10);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }).start();
        }
    }
}
