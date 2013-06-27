import java.awt.SystemTray;
import java.awt.TrayIcon;

public class MyClass {

  public static void main(String[] args) {

    // Create a pool for threads here
    WorkerThread[] threadPool = new WorkerThread[8];

    int index = 0;

    // Fill up the pool with threads
    for (WorkerThread workerThread : threadPool) {
      workerThread = new WorkerThread(index);
      threadPool[index] = workerThread;
      index++;
    }

    // Run threads
    for (WorkerThread workerThread : threadPool) {
      workerThread.start();
    }

    // Wait for threads to complete
    for (WorkerThread workerThread : threadPool) {
      try {
        workerThread.join();
      } catch (InterruptedException e) {
        // Handle the exception here
      }
    }

    SystemTray tray = SystemTray.getSystemTray();
    TrayIcon trayIcon = new TrayIcon(null);
    tray.add(trayIcon );
    System.out.println("Yay!");
    
    System.out.println("All threads are done");
  }
}
