package JAVA.TEST2;


class parent{

    void run()
    {
        System.out.println("RUNNING!");
    }


}



class child extends parent{

    @Override
    void run()
    {
        System.out.println("CHILD RUNNING");

    }


    void cry()
    {
        System.out.println("Crying!");
    }


}



