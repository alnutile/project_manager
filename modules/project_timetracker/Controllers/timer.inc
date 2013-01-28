<?php
class Timer
{
        private $_params;
        
        public function __construct($params)
        {
                $this->_params['uid'] = $params->uid;
                $this->_params['task'] = $params->task;
        }

        
        public function readAction()
        {       
                //read all the todo items while passing the username and password to authenticate
                $timer_items = TimeHandlers::getAllTimeItems($this->_params['uid'], $this->_params['task']);
                
                //return the list
                return $timer_items;
        }

        public function getAllTasks()
        {       
                //read all the todo items while passing the username and password to authenticate
                $all_tasks = TimeHandlers::getAllTimeTasks($this->_params['uid']);
                
                //return the list
                return $all_tasks;
        }
                

} 
