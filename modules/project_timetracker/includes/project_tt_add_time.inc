<?php
/**
 * @file
 * Add Time items to the db
 */
use Symfony\Component\HttpFoundation\JsonResponse;
/**
 * Add time to a task
 * @param Task id
 */
function project_tt_add_time() {
  //Create the time entry for the task
  //Return Success or Error message
  //This will be an entity
  //watchdog('time add', print_r($_POST, 1));
  $test[1] = 'test1';
  $test[2] = 'test2';
  global $user;
  if(count($_POST)) {
    $task = $_POST['tt_tasks'];
    $time = $_POST['tt_time'];
    $uid = $user->uid;
    db_insert('project_timer_entry')->
      fields(array(
        'pid' => NULL,
        'uid' => $uid,
        'seconds' => $time,
        'related_task' => $task,
        'created' => REQUEST_TIME,
        'updated' => REQUEST_TIME,
      )
    )->execute(); 
    
    //Get the times for this task chosen
    
    return new JsonResponse($test);
  } else {
    return new JsonResponse($test); 
  }
}

