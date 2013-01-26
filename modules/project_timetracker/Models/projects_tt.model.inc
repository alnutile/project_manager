 
<?php
class TimeHandlers
{
        
        public $time_seconds;
        public $task;
        public $uid;
        public $all_times;
        public $created;
        public $updated;
        public $pid;
        
        public static function getAllTimeItems($uid, $task)
        {
                $all_times = array();
                $query = db_select('project_timer_entry', 'pe');
                $query->fields('pe');
                $query->condition('uid', $uid, '=');
                $query->condition('related_task', $task, '=');
                $query->orderBy('created');
                $result = $query->execute();
                foreach($result as $row) {
                  $date = date('m-d-y', strtotime($row->created));
                  $time = $row->seconds;
                  $all_times[$row->pid] = "{$date} {$time}"; 
                }
                
                return $all_times;
        }
        /**
         * To edit or delete
         */
        public static function getItem($pid)
        {
                $timeArray = db_query("SELECT * FROM {project_timer_entry} WHERE pid = :pid", array(':pid' => $pid))->fetchAssoc();
                $time_record = new TimeHandlers();
                $time_record->time_seconds = $timeArray['seconds'];
                $time_record->task = $timeArray['task'];
                $time_record->uid = $timeArray['uid'];
                $time_record->created = $timeArray['created'];
                $time_record->updated = $timeArray['updated'];
                $time_record->pid = $timeArray['pid'];
                
                return $time_record;
        }
        
        public function delete($uid, $pid)
        {
                db_delete('project_timer_entry')->condition('pid', $pid, '=')->execute();
                return true;
        }
        
        public function save($uid, $time_seconds, $task)
        {
                
                //get the array version of this todo item
                $time_item_array = $this->toArray();
                db_insert('project_timer_entry')->
                  fields(array(
                    'pid' => NULL,
                    'uid' => $this->uid,
                    'seconds' => $this->time_seconds,
                    'related_task' => $this->task,
                    'created' => REQUEST_TIME,
                    'updated' => REQUEST_TIME,
                  )
                )->execute();                 
                //return the array version
                return $time_item_array;
        }
        
        public function toArray()
        {
                //return an array version of the todo item
                return array(
                        'todo_id' => $this->time_seconds,
                        'pid' => $this->pid,
                        'uid' => $this->uid,
                        'task' => $this->task,
                        'created' => $this->created,
                        'updated' => $this->updated
                );
        }
}